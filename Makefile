PHP_DIR         =   /usr/include/php5

INSTALL_PREFIX  =   /usr
INSTALL_HEADERS =   ${INSTALL_PREFIX}/include
INSTALL_LIB     =   ${INSTALL_PREFIX}/lib

RESULT          =   ip.so

COMPILER        =   g++
LINKER          =   g++

COMPILER_FLAGS  =   -Wall -c -I. -I${PHP_DIR} -I${PHP_DIR}/main -I${PHP_DIR}/ext -I${PHP_DIR}/Zend -I${PHP_DIR}/TSRM -g -std=c++11 -fpic -o

LINKER_FLAGS    =   -shared

RM              =   rm -f
CP              =   cp -f
MKDIR           =   mkdir -p

SOURCES         =   $(wildcard Ip/*.cpp)

OBJECTS         =   $(SOURCES:%.cpp=%.o)

all: ${OBJECTS} ${RESULT}

${RESULT}: ${OBJECTS}
	${LINKER} ${LINKER_FLAGS} -o $@ ${OBJECTS}

clean:
	${RM} ${OBJECTS} ${RESULT}

${OBJECTS}: 
	${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

install:
	${MKDIR} ${INSTALL_HEADERS}/phpcpp
	${CP} phpcpp.h ${INSTALL_HEADERS}
	${CP} include/*.h ${INSTALL_HEADERS}/phpcpp
	${CP} ${RESULT} ${INSTALL_LIB}

