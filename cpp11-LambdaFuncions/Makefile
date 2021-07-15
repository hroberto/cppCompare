.SUFFIXES:
.SUFFIXES: .o .ec .cpp

#pathprj=$(shell dirname $(shell dirname `pwd`))
pathprj=${PWD}
dirAplicacao=$(pathprj)/bin
dirBiblioteca=$(pathprj)/lib

nomeAplicacao=$(dirAplicacao)/demo


CCFLAGS = -DBOOST_LOG_DYN_LINK -DIFX_THREAD -D_REENTRANT -rdynamic
CCFLAGS_LIB = -fPIC  -shared -Wl,-soname,XXXX


## More Informations : https://gcc.gnu.org/projects/cxx-status.html

GCC_VERSION := $(shell echo `g++ -dumpversion | cut -f1-2  -d.` )
GCC_VERSION_C11 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 4.8 ) print 1;}' )
GCC_VERSION_C14 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 4.9 ) print 1;}' )
GCC_VERSION_C17 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 8 ) print 1;}' )
GCC_VERSION_C20 := $(shell echo $(GCC_VERSION) | awk '{if ($$1 >= 11 ) print 1;}' )

# ifeq ($(GCC_VERSION_C20),1)
#    CC = g++ -std=c++20  $(CCFLAGS)
# else
# ifeq ($(GCC_VERSION_C17),1)
#    CC = g++ -std=c++17  $(CCFLAGS)
# else ifeq ($(GCC_VERSION_C14),1)
#    CC = g++ -std=c++14  $(CCFLAGS)
# else
ifeq ($(GCC_VERSION_C11),1)
   CC = g++ -std=c++11 $(CCFLAGS)
else
	CC = g++ -std=c++98 ${GCC_VERSION} $(CCFLAGS)
endif



ifdef nomeBiblioteca
CC +=  $(CCFLAGS_LIB)
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

#-----------------------------------------------------
#Diretorios dos arquivos header (.h) do ESPECIFICO
#-----------------------------------------------------
INCLUDE_DIR	  =  -I$(DIR_SRC)

#-----------------------------------------------------
#Especifico
#-----------------------------------------------------
SRCS_CPP    = $(shell find $(DIR_SRC) -type f -name '*.cpp' 2> /dev/null)
OBJS   :=  $(SRCS_CPP:$(DIR_SRC)/%.cpp=$(DIR_OBJ)/%.o)
DEPS_FILES   :=  $(OBJS:$(DIR_OBJ)/%.o=$(DIR_DEP)/%.d)


ifeq ($(SO_KERNEL_NAME),Linux)
	LIB_SYS 		= -lpthread -ldl -lcrypt -lc
else
	LIB_SYS			= <<especificar para o SO>>
endif

LINK		= $(LIB_SYS)


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
	$(CC)  $(LINK) -o $(nomeAplicacao) $?
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
