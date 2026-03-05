#include <stdio.h>
#include <string.h>
#include <unistd.h>

int respond_error(int socket_fd, int fd, int status_code) {
	if (fd != -1) {
		close(fd);
	}

	const char *reason;
	switch (status_code) {
	case 400:
		reason = "Bad Request";
		break;
	case 404:
		reason = "Not Found";
		break;
	case 413:
		reason = "Content Too Large";
		break;
	case 500:
		reason = "Internal Server Error";
		break;
	default:
		reason = "Internal Server Error";
		break;
	}

	// small server size
	char response[256];
	snprintf(response, sizeof(response), "HTTP/1.1 %s\r\n\r\n", reason);

	write(socket_fd, response, strlen(response));

	return -1;
}

int respond_500(int socket_fd, int fd) {
	return respond_error(socket_fd, fd, 500);
}

int respond_400(int socket_fd, int fd) {
	return respond_error(socket_fd, fd, 400);
}

int respond_404(int socket_fd, int fd) {
	return respond_error(socket_fd, fd, 404);
}

int respond_413(int socket_fd, int fd) {
	return respond_error(socket_fd, fd, 413);
}
