#makefile for gaf-geda

# Input DIR using this directory structure cleans things upS
NAME= cable-tester
#
SCH=sch
PCB=pcb
SYM=gaf-symbols
FP=gaf_footprints
SS=subcircuits
FORCE=NO
# variables using the Make builtin shell expression/expansion
# not sure if = is a good assignment operator or if =! or =: would be better
DATE = $(shell date +"%b-%d-%Y")
AUTHOR = $(shell git config --global -l | grep user.name | cut -d "=" -f2)
REV = $(shell git describe --tags --long)
STATUS = $(shell git status -z -uno)
CHECKINS = $(shell git status --porcelain *.pcb *.sch)

pcb-files = $(wildcard *.pcb)
schematic-files = $(wildcard *.sch)
.PHONY: list-gedafiles clean
clean:
	rm -f *~ *- *.backup *.new.pcb *.png *.bak *.gbr *.cnc *.ps
list-gedafiles:
	@$(foreach asset, $(pcb-files), echo $(asset);)
	@$(foreach asset, $(schematic-files), echo $(asset);)

.PHONY: all
all: 
ifneq ($(FORCE),YES)
 ifneq ($(STATUS),)
 $(error error: bad working state -- clean working state and try again or use override)
 endif
 ifneq ($(CHECKINS),)
 $(error error: untracked schematic or pcb content, add content to repo, or use override)
 endif
 ifeq ($(REV),)
 $(error error: revision history has no tags to work with, add one and try again)
 endif
endif
# $@  is the automatic variable for the prerequisite
# $<  is the automatic variable for the target
#
# the following target exports postscript assets for the current commit using a
# tag format, that's why we need tags
ps : 
	@$(foreach asset, $(pcb-files), pcb -x ps --psfile $(REV)-$(asset).$@ $(asset);) 
# format schematic files with info for the commit, date, author, all
# assuming the CVS title block for gschem is included in the project and
# provided with a title: the following sed replacements work on variables found in CVS title blocks for gschem
	$(foreach asset, $(schematic-files), sed -i "s/\(date=\).*/\1$\$(DATE)/" $(asset);sed -i "s/\(auth=\).*/\1$\$(AUTHOR)/" $(asset); sed -i "s/\(fname=\).*/\1$@/" $(asset); sed -i "s/\(rev=\).*/\1$\$(REV) $\$(TAG)/" $(asset); gaf export -o $(REV)-$(asset).$@  -- $(asset); git checkout -- $(asset);)
# danger, we will discard changes to the schematic file in the working directory now.  This assumes that the working dir was clean before make was called and should be rewritten as an atomic operation
# GERBERS (props to https://github.com/bgamari)
#
.PHONY: gerbers osh-park-gerbers
gerbers: $(NAME).pcb 
	rm -Rf gerbers
	mkdir gerbers
	pcb -x gerber --gerberfile gerbers/$(name) $<
osh-park-gerbers: gerbers
	rm -Rf $@
	mkdir -p $@
	cp gerbers/$(name).top.gbr "$@/Top Layer.ger"
	cp gerbers/$(name).bottom.gbr "$@/Bottom Layer.ger"
	cp gerbers/$(name).topmask.gbr "$@/Top Solder Mask.ger"
	cp gerbers/$(name).bottommask.gbr "$@/Bottom Solder Mask.ger"
	cp gerbers/$(name).topsilk.gbr "$@/Top Silk Screen.ger"
	cp gerbers/$(name).bottomsilk.gbr "$@/Bottom Silk Screen.ger"
	cp gerbers/$(name).outline.gbr "$@/Board Outline.ger"
	cp gerbers/$(name).plated-drill.cnc "$@/Drills.xln"

osh-park-gerbers.zip : osh-park-gerbers
	rm -f $@
	zip -j $@ osh-park-gerbers/*
hackvana-gerbers : gerbers
	rm -Rf $@
	mkdir -p $@
	cp gerbers/$(name).top.gbr $@/$(name).front.gtl
	cp gerbers/$(name).bottom.gbr $@/$(name).back.gbl
	cp gerbers/$(name).topmask.gbr $@/$(name).frontmask.gts
	cp gerbers/$(name).bottommask.gbr $@/$(name).backmask.gbs
	cp gerbers/$(name).topsilk.gbr $@/$(name).frontsilk.gto
	cp gerbers/$(name).bottomsilk.gbr $@/$(name).backsilk.gbo
	cp gerbers/$(name).outline.gbr $@/$(name).outline.gbr
	cp gerbers/$(name).plated-drill.cnc $@/$(name).plated-drill.cnc
hackvana-gerbers.zip : hackvana-gerbers
	rm -f $@
	zip -j $@ hackvana-gerbers/*
	@echo "Be sure to add a version number to the zip file name"




