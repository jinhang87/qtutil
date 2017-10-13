
mybuild.target=mybuild
mybuild.commands=${COPY} $$PWD/lib/mylib.dll $$PWD


QMAKE_EXTRA_TARGETS += mybuild

#PRE_TARGETDEPS += mybuild
