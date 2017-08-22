# Include global vars
include($$PWD/../globals.pri)

# Include to compile with code coverage flags (gcov)
contains(catchTests, true) {
    CONFIG(debug, debug|release) {
        message(Activating gcov coverage compiler flags -> $$TARGET)
        QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
        QMAKE_LFLAGS += --coverage -fno-inline
        equals(QMAKE_CXX, g++) {
            QMAKE_LFLAGS += -lgcov
            QMAKE_LFLAGS += --coverage -fno-inline-small-functions -fno-default-inline
        }
        # Add clean -> remove .gcda .gcno
        for(source, SOURCES) {
            gcnoFile = $$replace(source, .cpp, .gcno)
            gcnaFile = $$replace(source, .cpp, .gcda)
            QMAKE_CLEAN += $$OUT_PWD/$$basename(gcnaFile)
            QMAKE_CLEAN += $$OUT_PWD/$$basename(gcnoFile)
        }
    }
}
