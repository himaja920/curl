#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

int main()
{
 CURL * curl = curl_easy_init();
 if(curl)
 {
    CURLcode res;
    curl_easy_setopt(curl,CURLOPT_URL,"http://10.10.10.100/api/QE6OvR5obnSdP82JolcKCUEsOQL5XFZOwvxd3g7h/lights");


    FILE *output_file = fopen("file1.json", "a+");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);


    /*char c;
    while((c = fgetc(output_file))!=EOF)
    {
     printf("%s",c);
    }*/

    fclose(output_file);
 }


}

