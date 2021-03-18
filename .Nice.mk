.EXTRA_PREREQS = Makefile .Nice.mk

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

cc?= gcc
# print status nicely (assumes ansi-compatible terminal)
empty:=
comma:= ,
printlist = [$1m$(subst $(empty) $(empty),[m$(comma) [$1m,$(2:$(3)%=[37m$(3)[$1m%))
print = echo '$(call printlist,33,$(1),$(2))	[37mfrom: $(call printlist,32,$(3),$(4))[m'

# Link
$(output): $(srcs:%=$(junkdir)/%.o)
	@$(call print,$@,,$^,$(junkdir)/)
	@$(cc) $(LDFLAGS) $^ $(libs:%=-l%) -o $@

# Compile
$(junkdir)/%.o $(junkdir)/%.mk &: $(srcdir)/%.c
	@mkdir -p $(@D)
	@$(call print,$(junkdir)/$*.o $(junkdir)/$*.mk,$(junkdir)/,$^,$(srcdir)/)
	@$(cc) $(CFLAGS) -MMD -MF$(junkdir)/$*.mk -MQ$(junkdir)/$*.mk -MQ$(<:%.c=$(junkdir)/%.o) -c $< -o $(junkdir)/$*.o

.PHONY: clean
clean:
	$(RM) -r $(junkdir)
	$(RM) $(output)

# found a way to make "clean" work!
# don't try to make clean at the same time as other goals though.
ifneq ($(MAKECMDGOALS),clean)
 ifeq (,$(findstring B,$(MAKEFLAGS)))
  include $(srcs:%=$(junkdir)/%.mk)
 endif
endif
