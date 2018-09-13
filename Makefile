SHELL=/bin/sh

.SILENT:
.IGNORE:

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
	echo '  * deps:  Installs Python build dependencies into a Pipenv environment'

.PHONY: build
build:
	pipenv run python setup.py bdist bdist_wheel
	rm -rf tmp/

.PHONY: dev
dev:
	pipenv install --dev

.PHONY: clean
clean:
	echo Cleaning ...
	rm -rf build/
	rm -rf tmp/
	echo ... done
