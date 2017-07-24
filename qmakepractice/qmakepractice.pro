


# split function
CONTACT = firstname:middlename:surname:phone
message($$split(CONTACT, :)) #firstname middlename surname phone

#first
CONTACT = firstname middlename surname phone
message($$first(CONTACT))

#last
CONTACT = firstname middlename surname phone
message($$last(CONTACT))

#list
for(var, $$list(foo bar baz)) {
    message($$var);
}

#unique
ARGS = 1 2 3 2 5 1
ARGS = $$unique(ARGS) #1 2 3 5
message($$ARGS);

# system
unix{
    UNAME = $$system(uname -s)
    contains( UNAME, [lL]inux ):message( This looks like Linux ($$UNAME) to me )
}

#basename
FILE = /etc/passwd
FILENAME = $$basename(FILE) #passwd

#dirname
FILE = /etc/X11R6/XF86Config
DIRNAME = $$dirname(FILE) #/etc/X11R6
message($$DIRNAME);

#find
MY_VAR = one two three four
MY_VAR2 = $$join(MY_VAR, " -L", -L) -Lfive
MY_VAR3 = $$member(MY_VAR, 2) $$find(MY_VAR, t.*)
message($$MY_VAR2);
message($$MY_VAR3);

