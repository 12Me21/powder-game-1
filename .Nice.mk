junkdir?= .junk
# location for intermediate files (.o and .mk)
# (will be created automatically, as well as any subdirectories)
# (ex: src `subdir/file` will create `.junk/subdir/` and compile `subdir/file.c` to `.junk/subdir/file.o`)
# (remember to update .gitignore if changed)

# print status nicely (assumes ansi-compatible terminal)
empty:=
comma:= ,
printlist = [$1m$(subst $(empty) $(empty),[m$(comma) [$1m,$(2:$(junkdir)/%=[37m$(junkdir)/[$1m%))
cc=@echo '$(call printlist,33,$@)	[37mfrom: $(call printlist,32,$^)[m' ; gcc

# Link
$(output): $(srcs:%=$(junkdir)/%.o)
	$(cc) $(CFLAGS) $(addprefix -l,$(libs)) $^ -o $@

# this uses a feature of gcc, which parses a C file
# and outputs a list of headers it depends on
$(junkdir)/%.mk: %.c
	$(cc) $(CFLAGS) -MM $< -MG -MP -MQ$@ -MQ$(<:%.c=$(junkdir)/%.o) -MF$@

# Compile
$(junkdir)/%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

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
 temp != mkdir -p $(addprefix $(junkdir)/,$(dir $(srcs)))
 include $(srcs:%=$(junkdir)/%.mk)
endif
