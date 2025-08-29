#pragma once

#include "OBSBasic.hpp"
#include <QWidget>

struct OBSBasicDroidCam : public OBSBasic {
#ifdef _WIN32
	bool nativeEvent(const QByteArray&, void*, qintptr*) override;
#endif
};
