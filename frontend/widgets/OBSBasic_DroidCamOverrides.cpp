#include "OBSBasic.hpp"

#include <QMenu>

void CleanMenuItems(QMenu *menu, bool recursive) {
	QAction *prevSeperator = nullptr;
	foreach(QAction *action, menu->actions()) {
		if (action->isSeparator()) {
			prevSeperator = action;
		}
		else if (recursive && action->menu()) {
			CleanMenuItems(action->menu(), false);
		}

		QString name;
		if (action->menu()) {
			name = action->menu()->objectName();
		} else {
			name = action->objectName();
		}
		blog(LOG_WARNING, name.toLocal8Bit().data());

		// File Menu
		if (name == QString::fromLocal8Bit("action_Settings"))
			continue;

		if (name == QString::fromLocal8Bit("actionShowSettingsFolder"))
			continue;

		if (name == QString::fromLocal8Bit("actionAlwaysOnTop")) {
			prevSeperator->setVisible(true);
			continue;
		}

		if (name == QString::fromLocal8Bit("actionE_xit")) {
			prevSeperator->setVisible(true);
			continue;
		}

		// View Menu
		if (name == QString::fromLocal8Bit("actionFullscreenInterface"))
			continue;

		if (name == QString::fromLocal8Bit("toggleStatusBar")) {
			prevSeperator->setVisible(true);
			continue;
		}

		if (name == QString::fromLocal8Bit("sceneListModeMenu"))
			prevSeperator->setVisible(true);

		if (name == QString::fromLocal8Bit("toggleListboxToolbars"))
			continue;
		if (name == QString::fromLocal8Bit("toggleContextBar"))
			continue;
		if (name == QString::fromLocal8Bit("toggleSourceIcons"))
			continue;
		if (name == QString::fromLocal8Bit("toggleStatusBar"))
			continue;

		// Help Menu
		if (name == QString::fromLocal8Bit("actionHelpPortal"))
			continue;
		if (name == QString::fromLocal8Bit("actionWebsite"))
			continue;

		if (name == QString::fromLocal8Bit("menuLogFiles")) {
			prevSeperator->setVisible(true);
			continue;
		}
		if (name == QString::fromLocal8Bit("actionShowLogs"))
			continue;
		if (name == QString::fromLocal8Bit("actionViewCurrentLog"))
			continue;

		if (name == QString::fromLocal8Bit("menuCrashLogs"))
			continue;
		if (name == QString::fromLocal8Bit("actionShowCrashLogs"))
			continue;

		if (name == QString::fromLocal8Bit("actionShowAbout")) {
			prevSeperator->setVisible(true);
			continue;
		}

		action->setVisible(false);
	}
}
