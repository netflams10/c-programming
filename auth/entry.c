#include <stdio.h>
#include <string.h>

// write and read files
void write_file(char username[20], char password[30]);
void read_file(char username[20]);

// invoke
void call(char username[20], int size);

// register and login
void create(char username[20]);
void login(char username[20]);
void read_auth();

// auth
void desktop();

const int auth_string_length = 20;
const int auth_file_string_length = 1000;

int main ()
{
    
  char username[auth_string_length];
  call(username, auth_string_length);
  return 0;
}

// The Desktop Console Entry point🤣
void desktop()
{
  printf("\nWelcome 🤝");
  printf("\nGive me your command 👽:\n");
}

void call (char username[20], int size)
{
  printf("Enter your Username: ");
  fgets(username, size, stdin);

  if (username) read_file(username);
}

void create(char username[20])
{
  char password[auth_string_length];
  char confirm_password[auth_string_length];

  printf("\nEnter your password: ");
  scanf("%s", password);

  printf("\nConfirm your password: ");
  scanf("%s", confirm_password);

  if (strcmp(password, confirm_password) == 0)
  {
    write_file(username, password);
    return;
  }
  printf("\nPassword is not the same \n");
}

void login(char username[20])
{
  char password[auth_string_length];
  char saved_password[] = "password";

  printf("\nEnter your password: ");
  scanf("%s", password);

  if (strcmp(password, saved_password) == 0)
  {
    printf("\n Password is the same");
    return;
  }
  printf("\nPassword is not the same \n");
}

void write_file (char username[auth_string_length], char password[auth_string_length])
{
  FILE* file_pointer = fopen(".secrets", "w");

  fprintf(file_pointer, "USERNAME=%s\n", username);
  fprintf(file_pointer,  "PASSWORD=%s\n", password);

  fclose(file_pointer);

  desktop();
}

void read_file (char username[auth_string_length])
{
  char stored_username[auth_string_length];
  char stored_password[auth_string_length];
  FILE* file_pointer = fopen(".secrets", "r");

  char file_content[auth_file_string_length];

  if (file_pointer == NULL) {
    create(username);
    return;
  } 

  while (fgets(file_content, auth_file_string_length, file_pointer)) {
    if (strstr(file_content, "PASSWORD") != NULL) {
      // sscanf -> search theough string with regex
      sscanf(file_content, "%*[^=]=%s", stored_password);
      break;
    }
  }
  printf("\n%s %s", file_content, stored_password);
  //   // login(username);

  fclose(file_pointer);
}

void read_auth()
{}



/*
* File Content
* USERNAME flams
* PASSWORD password
*/