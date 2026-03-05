#ifndef HANDLERS
#define HANDLERS

// common helpers
int respond_500(int socket_fd, int fd);
int respond_404(int socket_fd, int fd);
int respond_400(int socket_fd, int fd);
int respond_413(int socket_fd, int fd);

#endif
