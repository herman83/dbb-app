#ifndef DBB_APP_SETTINGSDIALOG_H
#define DBB_APP_SETTINGSDIALOG_H

#include <QDialog>

#include "dbb_configdata.h"

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

    DBB::DBBConfigdata *configData;

public slots:
    void resetDefaults();
    void cancel();
    void setHiddenPassword();
    void resetU2F();
    void useDefaultProxyToggled(int newState);
    
public:
    explicit SettingsDialog(QWidget *parent = 0, DBB::DBBConfigdata* configData = NULL, bool deviceLocked = false);
    ~SettingsDialog();

    void updateDeviceLocked(bool deviceLocked);
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);

signals:
    void settingsDidChange();
    void settingsShouldChangeHiddenPassword(const QString&);
    void settingsShouldResetU2F();

private:
    Ui::SettingsDialog *ui;
    void loadSettings();
    void storeSettings();
    void updateVisibility();
    
    bool cancleOnClose;
};

#endif //DBB_APP_SETTINGSDIALOG_H
