
gen-studio-api:
	rm -rf gen/*
	openapi-generator-cli generate \
	--generator-name cpp-qt5-client \
	--input-spec ~/Programmering/dt/api/openapi.yaml \
	--output gen \
	--model-package models \
	--api-package api \
	--strict-spec true
