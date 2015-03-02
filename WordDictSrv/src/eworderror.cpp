#include "eworderror.hpp"

const char *err2str(EErrorCode err)
{
    const char *str = nullptr;
    switch(err)
    {
    case E_SUCCESS:
        str = "No error";
        break;
    case E_ISERR:
        str = "Input System error";
        break;
    case E_OSERR:
        str = "Output System error";
        break;
    case E_WORDERR:
        str = "Word error";
        break;
    case E_EXPERR:
        str = "Explanation error";
        break;
    case E_EPERR:
        str = "Epoll error";
        break;
    case E_SKERR:
        str = "Socket error";
        break;
    case E_PPERR:
        str = "Pipe error";
        break;
    case E_USRERR:
        str = "User caused error";
        break;
    case E_MEMERR:
        str = "Memory error";
        break;
    case E_PARAERR:
        str = "Parameter error";
        break;
    case E_ERR:
        str = "Generic error";
        break;
    default:
        str = "Unrecognized error";
    }
    return str;
}
