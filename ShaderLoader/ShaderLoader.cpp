#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

static char* read_shader(const char* shaderPath) {
	int fileLen = 0;
	char* content = NULL;
	FILE* fp = NULL;
		
	fp = fopen(shaderPath, "r");
	if (!fp) {
		syslog(LOG_ERR, "Fail to open shader files %s", shaderPath);
		goto END;
	}
	fseek(fp, 0, SEEK_END);
	fileLen = ftell(fp);
	rewind(fp);
	
	if (NULL == (content = (cahr*)calloc(fileLen, sizeof(char)))) {
		syslog(LOG_ERR, "Fail to allocate enough memory for shader file.");
		goto END;
	}
	fread(content, sizeof(char), fileLen, content);

END:
	return content;
}

