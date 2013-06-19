#ifndef CHAR_HPP
#define CHAR_HPP

#include "../common/const_array.hpp"
#include "../common/mmo.hpp"

constexpr int MAX_MAP_SERVERS = 30;

#define CHAR_CONF_NAME  "conf/char_athena.conf"

#define LOGIN_LAN_CONF_NAME     "conf/lan_support.conf"

struct mmo_map_server
{
    long ip;
    short port;
    int users;
    char maps[MAX_MAP_PER_SERVER][16];
};

const mmo_charstatus *search_character(const char *character_name);

int mapif_sendall(const uint8_t *buf, unsigned int len);
int mapif_sendallwos(int fd, const uint8_t *buf, unsigned int len);
int mapif_send(int fd, const uint8_t *buf, unsigned int len);

void char_log(const_string line);

#define CHAR_LOG(fmt, ...)  \
    char_log(static_cast<const std::string&>(STRPRINTF(fmt, ## __VA_ARGS__)))

#endif // CHAR_HPP
