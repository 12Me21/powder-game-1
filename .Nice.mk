.EXTRA_PREREQS+= Makefile .Nice.mk

# location for intermediate files (.o and .mk)
# (will be created automatically, as well as any subdirectories)
# (ex: src `subdir/file` will create `.junk/subdir/` and compile `subdir/file.c` to `.junk/subdir/file.o`)
junkbase:= .junk
ifdef junkdir
 junkdir:= $(junkbase)/$(junkdir)
else
 junkdir:= $(junkbase)
endif
srcdir?= .

# print status nicely (assumes ansi-compatible terminal)
empty:=
comma:= ,
#printlist = [$1m$(subst $(empty) $(empty),[m$(comma) [$1m,$(2:$(3)%=[37m$(3)[$1m%))
printlist = [$1m$(subst $(empty) $(empty),[m$(comma) [$1m,$(2:$3%=[$1m%))
print = echo '$(call printlist,33,$1,$2)	[37mfrom: $(call printlist,32,$3,$4)[m'
#\time -f %e 

# Link
$(output): $(srcs:%=$(junkdir)/%.o)
	@$(call print,$@,,$^,$(junkdir)/)
	@$(CC) $(LDFLAGS) $^ $(libs:%=-l%) -o $@

# Compile
$(junkdir)/%.o $(junkdir)/%.mk &: $(srcdir)/%.c
	@mkdir -p $(@D)
	@$(call print,$(junkdir)/$*.o,$(junkdir)/,$^,$(srcdir)/)
	@$(CC) $(CFLAGS) -MMD -MF$(junkdir)/$*.mk -MQ$(junkdir)/$*.mk -MQ$(<:%.c=$(junkdir)/%.o) -c $< -o $(junkdir)/$*.o

.PHONY: clean
clean:
	$(RM) -r $(junkdir)
	$(RM) $(output)

ifneq ($(findstring clean,$(MAKECMDGOALS)),)
 #disable multiple jobs when clean is running, since that will break.
 .NOTPARALLEL:
else
 ifeq ($(findstring B,$(MAKEFLAGS)),)
# if `clean` is specified as a goal, or if the -B flag is passed,
# we skip including these files, because that will be redundant.
  include $(srcs:%=$(junkdir)/%.mk)
 endif
endif
