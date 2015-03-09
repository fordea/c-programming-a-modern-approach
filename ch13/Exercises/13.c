#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main(void)
{
    const char domain[] = "knking.com";
    char index_url[50];
    build_index_url(domain, index_url);
    printf("Domain: %s, index_url: %s", domain, index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}

