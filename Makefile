##
## EPITECH PROJECT, 2025
## B-OOP-400-NAN-4-1-tekspice-matisse.marsac
## File description:
## Makefile
##


GREEN = \033[0;32m
PURPLE = \033[0;34m
RESET = \033[0m

SRC	=	src/main.cpp \
		src/ComponentFactory.cpp \
		src/AComponent.cpp \
		src/IComponent.cpp \
		src/error/ErrorParser.cpp \
		src/error/CircuitException.cpp \
		src/componant/And.cpp \
		src/componant/AndThree.cpp \
		src/componant/Or.cpp \
		src/componant/Xor.cpp \
		src/componant/Not.cpp \
		src/componant/Nand.cpp \
		src/componant/Nor.cpp \
		src/componant/Input.cpp \
		src/componant/Output.cpp \
		src/componant/Clock.cpp \
		src/componant/True.cpp \
		src/componant/False.cpp \
		src/componant/Sum.cpp \
		src/componant/FlipFlop.cpp \
		src/componant/Counter.cpp \
		src/functions/LoopFunction.cpp \
		src/parsing/ParseFile.cpp \
		src/advanced-componants/Component4001.cpp	\
		src/advanced-componants/Component4008.cpp	\
		src/advanced-componants/Component4011.cpp	\
		src/advanced-componants/Component4013.cpp	\
		src/advanced-componants/Component4017.cpp	\
		src/advanced-componants/Component4030.cpp	\
		src/advanced-componants/Component4040.cpp	\
		src/advanced-componants/Component4069.cpp	\
		src/advanced-componants/Component4071.cpp	\
		src/advanced-componants/Component4081.cpp	\
		src/advanced-componants/Component4094.cpp	\
		src/advanced-componants/Component4512.cpp	\
		src/advanced-componants/Component4514.cpp	\
		src/advanced-componants/Component4801.cpp	\
		src/logic/logic.cpp				\
		src/componant/Logger.cpp

SRCT	=	src/error/ErrorParser.cpp 		\
			src/error/CircuitException.cpp 	\
			src/logic/logic.cpp				\
			src/componant/And.cpp			\
			src/componant/Xor.cpp			\
			src/componant/Or.cpp			\
			src/componant/Not.cpp			\
			src/AComponent.cpp				\
			src/componant/Clock.cpp			\
			src/componant/False.cpp			\
			src/componant/True.cpp			\
			src/componant/Output.cpp		\
			src/componant/Input.cpp			\
			src/componant/Nand.cpp			\
			src/componant/Nor.cpp			\
			src/advanced-componants/Component4001.cpp	\
			src/advanced-componants/Component4011.cpp	\
			src/advanced-componants/Component4030.cpp	\
			src/advanced-componants/Component4069.cpp	\
			src/advanced-componants/Component4071.cpp	\
			src/advanced-componants/Component4081.cpp	\

TEST_SRC =	tests/TestsError.cpp \
			tests/TestsErrorParser.cpp	\
			tests/TestsLogic.cpp		\
			tests/TestsAnd.cpp			\
			tests/TestXor.cpp			\
			tests/TestsOr.cpp			\
			tests/TestsNot.cpp			\
			tests/TestsClock.cpp		\
			tests/TestsFalse.cpp		\
			tests/TestsTrue.cpp			\
			tests/TestsOutput.cpp		\
			tests/TestsInputs.cpp		\
			tests/TestsNand.cpp			\
			tests/TestsNor.cpp			\
			tests/Tests4001.cpp			\
			tests/Tests4011.cpp			\
			tests/Tests4030.cpp			\
			tests/Tests4069.cpp			\
			tests/Tests4071.cpp			\
			tests/Tests4081.cpp			\

NAME	=	nanotekspice

TEST_NAME =	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

CFLAGS	+= -std=c++20 -Wall -Wextra

C_STYLE	=	coding-style-reports.log

all:
	@for file in $(SRC); do \
		echo -e "$(GREEN){✓} $${file#src/}$(RESET)"; \
		g++ -c $$file $(CFLAGS); \
	done
	@g++ -o $(NAME) *.o $(LDFLAGS)
	@rm -f *.o

unit_tests:	clean
	@g++ -o $(TEST_NAME) $(SRCT) $(TEST_SRC) $(LDFLAGS) $(TEST_FLAGS)

re: fclean all

tests_run:	unit_tests
	@./$(TEST_NAME)

clean:
	@rm -rf *.o
	@rm -rf *.gc*
	@rm -rf coding-style-reports.log

fclean: clean
	@rm -f $(TEST_NAME)
	@rm -rf $(C_STYLE)
	@rm -f $(NAME)

coverage: tests_run
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branch
