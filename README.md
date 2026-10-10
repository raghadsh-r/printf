*This project has been created as part of the 42 curriculum by ralshraw*
# Description
it's have all libft library in c , and good function you can use it in your program and this can help you to understand good how memory work .
libft library and some additional functions :

### Part 1 - Libc functions :
| Function | Description |
| :--- | :--- |
| **isalpha** | check if the char is alpha |
| **isdigit** | check if the char is digital |
| **isalnum** | check if the char is alpha or digital |
| **isascii** | check if the char is ascii |
| **isprint** | check if the char is printable |
| **strlen** | count the len of the string |
| **memset** | change the char in memory into n limits |
| **bzero** | like memset but it puts '\0' char |
| **memcpy** | copy from src to dst, doesn't handle overlap |
| **memmove** | copy from src to dst, handles overlap |
| **strlcpy** | copy from src to dst, more safer |
| **strlcat** | concat the src to dst, more safer |
| **toupper** | change char to upper |
| **tolower** | change char to lower |
| **strchr** | find the first appearance of the letter |
| **strrchr** | find the last appearance of the letter |
| **strncmp** | compares up to num characters |
| **memchr** | find the first appearance of the letter |
| **memcmp** | compares memory |
| **strnstr** | locates the first occurrence of s2 in s1 |
| **atoi** | change from string to int |

### Part 2 - Additional functions :
| Function | Description |
| :--- | :--- |
| **ft_substr** | returns a substring of the string s passed as parameter. |
| **ft_strjoin** | return the join of to string |
| **ft_strtrim** | remove the first and last appearance to string |
| **ft_split** | take strings and delimiter char c and divide s into bunch of smaller strings |
| **ft_itoa** | chang the int to ascii |
| **ft_strmapi** | Maps a function to characters of a string and their indices Applies the function f to each character and return string |
| **ft_striteri** | Maps a function to characters of a string and their indices Applies the function f to each character |
| **ft_putchar_fd** |  write character c on a specified file descriptor |
| **ft_putstr_fd** | write string c on a specified file descriptor |
| **ft_putendl_fd** | write a string on a specified file descriptor, follow by a newline |
| **ft_putnbr_fd** | write an int on a specified file descriptor |

### Part 3 - linked list
| Function | Description |
| :--- | :--- |
| **ft_lstnew** | make new node and return it |
| **ft_lstadd_front** | add new node to the front of node |
| **ft_lstsize** | count the number of the node  |
| **ft_lstlast** | Returns the last node of the list |
| **ft_lstadd_back** |  add new node to the back of node |
| **ft_lstdelone** | delet the node |
| **ft_lstclear** | remove all node in linked list |
| **ft_lstiter** |  Iterates through the list lst and applies the function f to the content of each node |
| **ft_lstmap** | Iterates through the list lst, applies the function f to each node content, and creates new list |

- > you can use atio fun to make culcuter or calloc to allocate loction etc........

# Instructions
* You can run it just by this command: `make`
* If you want to delete `.o` files: `make clean`
* You must have a C compiler and valgrind if you want to see memory leaks.
* If you face any problems or issues, you can use terminal `help`.
* And if you don't know what a function makes, use: `man <function name>`
# Resources
i dependend on a lot of resources

- >  https://www.youtube.com/watch?v=DyqstSE470s
- >  https://www.youtube.com/watch?v=Q2u1ZGUUtZE
- >  https://stackoverflow.com/questions/1043034/what-does-void-mean-in-c-c-and-c
- >  https://www.w3schools.com/c/c_error_handling.php
- >  https://www.w3schools.com/c/c_structs_padding.php
- >  https://www.youtube.com/watch?v=ZLc_OpzND2c
- >  https://www.youtube.com/watch?v=CEErMCLG_Wg&list=PLkH1REggdbJpmQKm8Nu-H8R81_-c00fpB
- >   and if course some of my code in picin 

