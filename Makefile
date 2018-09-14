SHELL=/bin/sh

.SILENT:
.IGNORE:

.PHONY: dev
dev: build
	pipenv install -e .

.PHONY: help
help:
	echo
	echo 'Utility Makefile
	echo '================
	echo
	echo 'Targets supported are:'
	echo
	echo '  * clean: remove all build artefacts'
	echo '  * build: builds the Python package'
	echo '  * install:  builds and installs into pipenv environment'
	echo '  * test:  runs unit tests'
	echo '  * help:  display help message'

.PHONY: build
build:
	pipenv run python setup.py bdist bdist_wheel
	rm -rf tmp/

.PHONY: clean
clean:
	echo Cleaning ...
	rm -rf build/
	rm -rf tmp/
	echo ... done

.PHONY: test
test:
	pytest ./tests
