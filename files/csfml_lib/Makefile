##
## EPITECH PROJECT, 2025
## probable-octo-enigma-my_runner
## File description:
## Makefile
##

CSFML_ZIP = CSFML-2.5-sources.zip
CSFML_URL = https://www.sfml-dev.org/files/CSFML-2.5-sources.zip
CSFML_DIR = CSFML-2.5
SFML_ZIP = SFML-2.5.1-sources.zip
SFML_URL = https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip
SFML_DIR = SFML-2.5.1
BUILD_DIR = build
SFML_BUILD = build-sfml
CSFML_BUILD = build-csfml
SFML_INSTALL = $(CURDIR)/sfml_install
INSTALL_DIR = $(CURDIR)/install

all: install-sfml install-csfml

# --- SFML targets ---
download-sfml:
	if [ -f "$(SFML_ZIP)" ]; then \
		echo "$(SFML_ZIP) already exists, skipping download"; \
	else \
		echo "Downloading $(SFML_ZIP)..."; \
		if command -v curl >/dev/null 2>&1; then \
			curl -L -o "$(SFML_ZIP)" "$(SFML_URL)"; \
		else \
			wget -O "$(SFML_ZIP)" "$(SFML_URL)"; \
		fi; \
	fi

extract-sfml: download-sfml
	if [ -d "$(SFML_DIR)" ]; then \
		echo "$(SFML_DIR) already extracted"; \
	else \
		echo "Extracting $(SFML_ZIP) ..."; \
		unzip -q "$(SFML_ZIP)"; \
		mv SFML-* "$(SFML_DIR)" 2>/dev/null || true; \
	fi

build-sfml: extract-sfml
	mkdir -p "$(SFML_BUILD)"
	cd "$(SFML_BUILD)" && cmake ../$(SFML_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=OFF \
		-DCMAKE_INSTALL_PREFIX="$(SFML_INSTALL)"
	$(MAKE) -C "$(SFML_BUILD)" -j$(shell nproc || echo 1)

install-sfml: build-sfml
	$(MAKE) -C "$(SFML_BUILD)" install
	echo "SFML built and installed to $(SFML_INSTALL)"

# --- CSFML targets ---
download-csfml:
	if [ -f "$(CSFML_ZIP)" ]; then \
		echo "$(CSFML_ZIP) already exists, skipping download"; \
	else \
		echo "Downloading $(CSFML_ZIP)..."; \
		if command -v curl >/dev/null 2>&1; then \
			curl -L -o "$(CSFML_ZIP)" "$(CSFML_URL)"; \
		else \
			wget -O "$(CSFML_ZIP)" "$(CSFML_URL)"; \
		fi; \
	fi

extract-csfml: download-csfml
	if [ -d "$(CSFML_DIR)" ]; then \
		echo "$(CSFML_DIR) already extracted"; \
	else \
		echo "Extracting $(CSFML_ZIP) ..."; \
		unzip -q "$(CSFML_ZIP)"; \
		mv CSFML-* "$(CSFML_DIR)" 2>/dev/null || true; \
	fi

build-csfml: extract-csfml install-sfml
	mkdir -p "$(CSFML_BUILD)"
	cd "$(CSFML_BUILD)" && cmake ../$(CSFML_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=OFF \
		-DSFML_DIR="$(SFML_INSTALL)/lib/cmake/SFML" \
		-DCMAKE_INSTALL_PREFIX="$(INSTALL_DIR)"
	$(MAKE) -C "$(CSFML_BUILD)" -j$(shell nproc || echo 1)

install-csfml: build-csfml
	$(MAKE) -C "$(CSFML_BUILD)" install
	echo "CSFML built and installed to $(INSTALL_DIR)"

clean:
	rm -rf "$(SFML_BUILD)" "$(CSFML_BUILD)" "$(SFML_DIR)" "$(CSFML_DIR)"

fclean: clean
	rm -f "$(SFML_ZIP)" "$(CSFML_ZIP)"


.PHONY: all download-sfml extract-sfml build-sfml install-sfml \
        download-csfml extract-csfml build-csfml install-csfml \
        all clean fclean
