.PHONY: clean All

All:
	@echo "----------Building project:[ Board_Game - Debug ]----------"
	@cd "Board_Game" && "$(MAKE)" -f  "Board_Game.mk"
clean:
	@echo "----------Cleaning project:[ Board_Game - Debug ]----------"
	@cd "Board_Game" && "$(MAKE)" -f  "Board_Game.mk" clean
