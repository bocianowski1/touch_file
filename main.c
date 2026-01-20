#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>


#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    printf("No file(s) created. Provide a path like './cmd/server/main.go'.\n");
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    printf("Creating %s\n", argv[i]);

    char s[256];
    int j = 0;

    for (int k = 0; argv[i][k] != '\0'; k++) {
      s[j++] = argv[i][k];

      if (argv[i][k] == '/') {
        s[j] = '\0';

        if (mkdir(s, 0777) != 0) {
          printf("%s already exists\n", s);
        }
      }
    }

    FILE *f = fopen(argv[i], "w");
    if (!f) {
      perror("fopen");
    } else {
      fclose(f);
    }
  }

  return 0;
}

