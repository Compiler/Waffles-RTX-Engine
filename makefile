BUILD_SCRIPTS_LOC = build_scripts\\

all: main

main:
	$(BUILD_SCRIPTS_LOC)build.bat

launch:
	$(BUILD_SCRIPTS_LOC)build_run.bat

run:
	$(BUILD_SCRIPTS_LOC)run.bat

clean:
	$(BUILD_SCRIPTS_LOC)clean.bat
