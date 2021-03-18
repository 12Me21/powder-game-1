# location for intermediate files (.o and .mk)
# (will be created automatically, as well as any subdirectories)
# (ex: src `subdir/file` will create `.junk/subdir/` and compile `subdir/file.c` to `.junk/subdir/file.o`)
# (remember to update .gitignore if changed)
junkbase:= .junk
ifdef junkdir
 junkdir:= $(junkbase)/$(junkdir)
else
 junkdir:= $(junkbase)
endif
srcdir?= .

gcc?= gcc
# print status nicely (assumes ansi-compatible terminal)
empty:=
comma:= ,
printlist = [$1m$(subst $(empty) $(empty),[m$(comma) [$1m,$(2:$(3)%=[37m$(3)[$1m%))
print = echo '$(call printlist,33,$(1),$(2))	[37mfrom: $(call printlist,32,$(3),$(4))[m'

# Link
$(output): $(srcs:%=$(junkdir)/%.o)
	@$(call print,$@,,$^,$(junkdir)/)
	@$(gcc) $(LDFLAGS) $^ $(addprefix -l,$(libs)) -o $@

# this uses a feature of gcc, which parses a C file
# and outputs a list of headers it depends on
#$(junkdir)/%.mk: $(srcdir)/%.c
#	$(cc) $(CFLAGS) -DHDEPS -MM $< -MP -MQ$@ -MQ$(<:%.c=$(junkdir)/%.o) -MF$@

# Compile
$(junkdir)/%.o $(junkdir)/%.mk &: $(srcdir)/%.c
	@mkdir -p $(@D)
#$(addprefix -I,$(includes))
# -MP ?
	@$(call print,$(junkdir)/$*.o $(junkdir)/$*.mk,$(junkdir)/,$^,$(srcdir)/)
	@$(gcc) $(CFLAGS) -MMD -MF$(junkdir)/$*.mk -MQ$(junkdir)/$*.mk -MQ$(<:%.c=$(junkdir)/%.o) -c $< -o $(junkdir)/$*.o

.PHONY: clean
clean:
	$(RM) -r $(junkdir)
	$(RM) $(output)

# found a way to make "clean" work!
# don't try to make clean at the same time as other goals though.
ifneq ($(MAKECMDGOALS),clean)
 # Normally, Make will try to generate nonexistent included files (in this case, with our $(junkdir)/%.mk rule
 # But for some reason, include fails if the file is in a nonexistent directory.
 # This is the only solution I can think of:
# temp != mkdir -p $(addprefix $(junkdir)/,$(dir $(srcs)))
 ifeq (,$(findstring B,$(MAKEFLAGS)))
  include $(srcs:%=$(junkdir)/%.mk)
 endif
endif

.EXTRA_PREREQS = Makefile .Nice.mk
