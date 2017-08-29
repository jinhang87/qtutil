TEMPLATE = aux

IDE_SOURCE_TREE = $$PWD
wd = $$replace(IDE_SOURCE_TREE, /, $$QMAKE_DIR_SEP)

mytarget.target = .updatefile
mytarget.commands = @echo $$wd
mytarget.depends = mytarget2

mytarget2.commands = @echo Building $$mytarget.target
QMAKE_EXTRA_TARGETS += mytarget mytarget2

