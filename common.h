#ifndef COMMON_H
#define COMMON_H

#define MESSAGE_LEN 512
#define INT_STR_LEN 16

#include <iostream>
#include "aes.h"

enum ClientStatus {
    CLIENT_CONNECTED,
    CLIENT_LOGGEDIN,
    CLIENT_DISCONNECTED
};

int encrypted_send(int fd, const char* buf, size_t len, int flags) {
    char* encrypt_string = NULL;
    int encrypt_len = encrypt(buf, &encrypt_string);
    return send(fd, encrypt_string, encrypt_len, 0);
}

int decrypted_recv(int fd, char* buf, size_t len, int flags) {
    char *decryto_string = NULL;
    char beforeDecrypt[MESSAGE_LEN] = {0};
    int ret = recv(fd, beforeDecrypt, len, flags);
    if (ret == 0) return 0;

    decrypt(beforeDecrypt, &decryto_string, ret);
    strcpy(buf, decryto_string);
    return ret;
}

#endif
