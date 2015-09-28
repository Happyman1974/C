#include <stdio.h>
#include <stdlib.h>
#include "mysql/mysql.h"

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{      
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "user12", "34klq*", 
          "testdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "DELETE FROM `Cars` WHERE `calldate` > '2015-05-13 12:49:20'")) 
  {
      finish_with_error(con);
  }
  
  mysql_close(con);
  
  exit(0);
}
