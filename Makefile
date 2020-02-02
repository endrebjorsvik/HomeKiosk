
gen-studio-api-qt:
	rm -rf gen/*
	openapi-generator-cli generate \
	--generator-name cpp-qt5-client \
	--input-spec ~/Programmering/dt/api/openapi.yaml \
	--output gen \
	--model-package models \
	--api-package api \
	--strict-spec true

gen-studio-api-cpp:
	rm -rf gencpp/*
	openapi-generator-cli generate \
	--generator-name cpp-restsdk \
	--input-spec ~/Programmering/dt/api/openapi.yaml \
	--output gencpp \
	--model-package models \
	--api-package api \
	--strict-spec true

gen-studio-api-python:
	rm -rf genpython/*
	openapi-generator-cli generate \
	--generator-name python \
	--input-spec ~/Programmering/dt/api/openapi.yaml \
	--output genpython \
	--package-name dtapi_client \
	--strict-spec true

dummy:
	--package-url "https://tjafs.org/blabla" \
	--package-version 1.0.0 \
	--project-name "dtapi-client" \
