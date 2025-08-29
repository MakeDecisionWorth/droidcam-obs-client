#pragma once

#if DROIDCAM_OVERRIDE
constexpr const char *VIRTUAL_CAM_ID = "droidcam_virtual_output";
#else
constexpr const char *VIRTUAL_CAM_ID = "virtualcam_output";
#endif

enum VCamOutputType {
	Invalid,
	SceneOutput,
	SourceOutput,
	ProgramView,
	PreviewOutput,
};

// Kept for config upgrade
enum VCamInternalType {
	Default,
	Preview,
};

struct VCamConfig {
	VCamOutputType type = VCamOutputType::ProgramView;
	std::string scene;
	std::string source;
};
