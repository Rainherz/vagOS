#ifndef FILESYSTEM_H
#define FILESYSTEM_H

void init_filesystem();
void list_files();
void create_file(const char *filename, const char *content);
void delete_file(const char *filename);
void show_file_content(const char *filename);

#endif

