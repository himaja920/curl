#include<stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <curl/curl.h>
int  main(int *argc,char ** argv)
{
  CURL *curl;
  CURLcode res;
  char * url = argv[1];
  if(argc < 2)
  return 1;
    /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {

       curl_easy_setopt(curl, CURLOPT_URL ,url);



       FILE *output_file = fopen("file1.json", "a+");
       curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);
       curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 2L);


       res = curl_easy_perform(curl);

       curl_easy_cleanup(curl);
       fclose(output_file);
}
   printf("\n");

  return 0;
}

