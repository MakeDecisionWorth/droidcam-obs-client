#pragma once

#include "OBSBasic.hpp"
#include <QWidget>

struct OBSBasicDroidCam : public OBSBasic {
	void OBSInit() override;

#ifdef _WIN32
	bool nativeEvent(const QByteArray&, void*, qintptr*) override;
#endif

private slots:
};
