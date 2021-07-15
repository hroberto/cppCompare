.SUFFIXES:
.SUFFIXES: .o .ec .cpp

#pathprj=$(shell dirname $(shell dirname `pwd`))
pathprj=${PWD}
dirAplicacao=$(pathprj)/bin
dirBiblioteca=$(pathprj)/lib

nomeAplicacao=$(dirAplicacao)/binTester
# nomeBiblioteca=$(dirBiblioteca)/libmotor_template.so

versao=$(shell svnversion -n | grep '[0-9]' )

GCC_VERSION_C11 := $(shell expr `g++ -dumpversion | cut -f1-2  -d.` \>= 4.8 )

#CCFLAGS =  -Wall -Werror -O3 -DIFX_THREAD -D_REENTRANT -rdynamic
CCFLAGS =  -Wall -Werror -DBOOST_LOG_DYN_LINK -DIFX_THREAD -D_REENTRANT -rdynamic
CCFLAGS_LIB = -fPIC  -shared -Wl,-soname,XXXX
CCFLAGS_BIN =  -DSVN_REVISION=\"$(versao)\"

ifeq ($(GCC_VERSION_C11),1)
   CC = g++ -std=c++11 $(CCFLAGS)
else
	CC = g++ -std=c++98 ${GCC_VERSION} $(CCFLAGS)
endif



ifdef nomeBiblioteca
CC +=  $(CCFLAGS_LIB)
else
CC +=  $(CCFLAGS_BIN)
endif


SO_KERNEL_NAME	= $(shell uname)
SO_PLATAFORM	= $(shell uname -i)

AR = ar
XSD = xsd
DIR_COMPILADOR_ESQL = $(INFORMIXDIR)/bin


DIR_SRC= $(pathprj)/src
DIR_OBJ= $(pathprj)/.obj
DIR_DEP= $(pathprj)/.dep

dirLibrary = $(pathprj)/Library
DIR_INCL_UTIL         = ${dirLibrary}/Util/include/MaquinaRegras/Util
DIR_INCL_DATA_SOURCE  = ${dirLibrary}/DataSource/include/MaquinaRegras/DataSource
DIR_INCL_PESQUISAS  = ${dirLibrary}/Pesquisas/include/MaquinaRegras/Pesquisas
DIR_INCL_GRAFOS  = ${dirLibrary}/Grafos/include/MaquinaRegras/Grafos

ORIZON_BASE_VALID=$(shell  [ -d $(ORIZON_BASE) ] && echo $(ORIZON_BASE) )
BASE_ORIZON_PRJ_VALID=$(shell  [ -d $(BASE_ORIZON_PRJ) ] && echo $(BASE_ORIZON_PRJ) )
POCO_BASE_VALID=$(shell  [ -d $(POCO_BASE) ] && echo $(POCO_BASE) )
PRJ_INCLUDE_VALID=$(shell  [ -d $(PWD)/include ] && echo $(PWD)/include )


DIR_ORIZON_HTTP 		= $(ORIZON_BASE)/HTTP/include
DIR_ORIZON_MESSAGES 	= $(ORIZON_BASE)/Messages/include
DIR_ORIZON_DATA 		= $(ORIZON_BASE)/Data/include
DIR_ORIZON_FOUNDATION 	= $(ORIZON_BASE)/Foundation/include
DIR_ORIZON_CONNECTORS 	= $(ORIZON_BASE)/Connectors/include

DIR_CPP_ORIZON 	= $(BASE_ORIZON_PRJ)/include


DIR_POCO_FOUNDATION 	= $(POCO_BASE)/Foundation/include
DIR_POCO_XML 			= $(POCO_BASE)/XML/include
DIR_POCO_UTIL 			= $(POCO_BASE)/Util/include
DIR_POCO_NET 			= $(POCO_BASE)/Net/include

#PocoNet PocoNetSSL PocoData PocoODBC PocoUtil PocoXML PocoFoundation

#-----------------------------------------------------
#Diretorios dos arquivos header (.h)
#-----------------------------------------------------
ifneq ($(ORIZON_BASE_VALID),)
INCLUDE_DIR_LIBORIZON 	= -I$(DIR_ORIZON_HTTP) -I$(DIR_ORIZON_MESSAGES) -I$(DIR_ORIZON_FOUNDATION) -I$(DIR_ORIZON_CONNECTORS) -I$(DIR_ORIZON_DATA)
endif
ifneq ($(BASE_ORIZON_PRJ_VALID),)
INCLUDE_DIR_LIBORIZON 	= -I$(DIR_CPP_ORIZON)
endif

ifneq ($(POCO_BASE_VALID),)
INCLUDE_DIR_LIBPOCO 	=  -I$(DIR_POCO_FOUNDATION) -I$(DIR_POCO_XML) -I$(DIR_POCO_UTIL) -I$(DIR_POCO_NET)
endif
#INCLUDE_DIR_OMR         = -I$(DIR_INCL_UTIL) -I$(DIR_INCL_DATA_SOURCE) -I$(DIR_INCL_PESQUISAS) -I$(DIR_INCL_GRAFOS)
#INCLUDE_DIR_SISTEMA  = -I$(DIR_INFORMIX) -I$(DIR_XERCES) -I$(DIR_SYSTEM) -I$(DIR_ZLIB) -I$(DIR_WEBSTATUSCON)


#-----------------------------------------------------
#Diretorios dos arquivos header (.h) do ESPECIFICO
#-----------------------------------------------------
INCLUDE_DIR	  =  -I$(DIR_SRC)

ifneq ($(PRJ_INCLUDE_VALID),)
	INCLUDE_DIR   += -I $(PRJ_INCLUDE_VALID)
endif
ifneq ($(INCLUDE_DIR_LIBORIZON),)
	INCLUDE_DIR   +=  $(INCLUDE_DIR_LIBORIZON)
endif
ifneq ($(INCLUDE_DIR_LIBPOCO),)
	INCLUDE_DIR   += $(INCLUDE_DIR_LIBPOCO)
endif
ifneq ($(INCLUDE_DIR_OMR),)
	INCLUDE_DIR   +=  -I$(INCLUDE_DIR_OMR)
endif
ifneq ($(BASE_BOOST),)
	INCLUDE_DIR   += -I${BASE_BOOST} -I$(BASE_ACTIVE_MQ_CPP) -I$(BASE_APR_1)
endif


#-----------------------------------------------------
#Especifico
#-----------------------------------------------------
#SRCS_CPP    = $(shell ls $(DIR_SRC)/*.cpp 2> /dev/null)
#OBJS 		= $($(SRCS_CPP:.cpp=.o):$(DIR_SRC)=$(DIR_OBJ))
SRCS_CPP    = $(shell find $(DIR_SRC) -type f -name '*.cpp' 2> /dev/null)
OBJS   :=  $(SRCS_CPP:$(DIR_SRC)/%.cpp=$(DIR_OBJ)/%.o)
DEPS_FILES   :=  $(OBJS:$(DIR_OBJ)/%.o=$(DIR_DEP)/%.d)

#LIB_OMR = -L $(dirBiblioteca) -lOmrUtil -lOmrDataSource -lOmrPesquisas -lOmrGrafos

ifeq ($(SO_KERNEL_NAME),Linux)
	LIB_SYS 		= -lpthread -ldl -lcrypt -lc

	ifneq ($(INFORMIXDIR),)
		LIB_ESQL        = -L $(INFORMIXDIR)/lib -lthasf -L $(INFORMIXDIR)/lib/esql -lthgen -lthsql -lgls -lthos $(INFORMIXDIR)/lib/esql/checkapi.o
	endif

	ifneq ($(ORIZON_BASE_VALID),)
		LIB_ORIZON      = -L $(ORIZON_BASE)/lib/Linux/$(SO_PLATAFORM) -lOrizonHTTP -lOrizonMessages -lOrizonFoundation -lOrizonConnectors -lOrizonData
	endif
	ifneq ($(BASE_ORIZON_PRJ_VALID),)
		LIB_ORIZON_CPP      = -L$(BASE_ORIZON_PRJ)/lib -lorizon_utils -lorizon_odbc -lorizon_thread_ipc
	endif
	ifneq ($(POCO_BASE),)
		LIB_POCO        = -L $(POCO_BASE)/lib/Linux/$(SO_PLATAFORM) -lPocoFoundation -lPocoXML -lPocoUtil -lPocoNet -lPocoNetSSL
	endif
else
	LIB_SYS			= <<especificar para o SO>>
endif
ifneq ($(BASE_BOOST_LIBS),)
	LIB_BOOST = -lcppunit -lodbc -lactivemq-cpp \
		-L ${BASE_BOOST_LIBS} \
		-lboost_filesystem -lboost_system -lboost_iostreams -lboost_date_time -lboost_regex -lboost_thread -lboost_chrono \
		-lboost_program_options -lboost_locale \
		-lboost_log
endif
#Link das Bibliotecas
LINK		= $(LIB_SYS) $(LIB_OMR) $(LIB_ORIZON) $(LIB_ORIZON_CPP) $(LIB_POCO) $(LIB_ESQL) \
				  $(LIB_BOOST)


$(DIR_DEP)/%.d:  $(DIR_SRC)/%.cpp
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@echo "| Criando dependencia >>> $@"
	$(CC) -MM $(INCLUDE_DIR)  $< > $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@echo "$(shell basename $(abspath $(dir $@))) | Compilando  >>> `basename $<`"
	$(CC) -Wno-deprecated  $(INCLUDE_DIR) -c $< -o $@

all: $(OBJS)
	@echo "------------------------------------------------------------------------------"

ifneq ($(nomeAplicacao),)
	@[ -d $(dirAplicacao) ] || mkdir $(dirAplicacao)

	echo "Criando binario <$(nomeAplicacao)>"
	@rm -f $(nomeAplicacao)
	$(CC)  $(CCFLAGS_BIN) $(LINK) -o $(nomeAplicacao) $?
	@chmod 770 $(nomeAplicacao)
else
	@[ -d $(dirBiblioteca) ] || mkdir $(dirBiblioteca)

	echo "Criando biblioteca <$(nomeBiblioteca)>"
	$(CC) $(LINK) -o $(nomeAplicacao) $?
endif


	@echo "<<<<<< Feito >>>>>>"
	@echo "------------------------------------------------------------------------------"

local: $(OBJS)
	@echo "----------------------------------------"
	@echo "Criando autorizador <$(nomeAplicacao)>"
	@rm -f $(nomeAplicacao)
	@$(CC) $?  $(LINK) -o $(nomeAplicacao)
	@chmod 770 $(nomeAplicacao)
	@echo "<<<<<< Feito >>>>>>"
	@echo "----------------------------------------"

clean:
	@echo "-------------------------------------------------"
	@echo "Apagando Objs/dependencias de <$(nomeAplicacao)>"
	rm -f $(OBJS:.o=.d) $(OBJS) core* $(nomeAplicacao)
	rm -fr $(DIR_OBJ)  $(DIR_DEP) $(dirAplicacao) $(dirBiblioteca)

	@echo "<<<<<< Feito >>>>>>"
	@echo "-------------------------------------------------"

#-include $(OBJS:.o=.d)
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS_FILES)
endif
