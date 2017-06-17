TEMPLATE = aux

IDE_SOURCE_TREE = $$PWD
wd = $$replace(IDE_SOURCE_TREE, /, $$QMAKE_DIR_SEP)
LUPDATE = $$shell_path($$[QT_INSTALL_BINS]/lupdate) -locations relative -no-ui-lines -no-sort
!build_pass:message($$wd)

mytarget.target = .updatefile
mytarget.commands = cd $$wd && cd $$wd
mytarget.depends = mytarget2

mytarget2.commands = @echo Building $$mytarget.target
QMAKE_EXTRA_TARGETS += mytarget mytarget2
