#ifndef __COURSEGEN_WIDGET_H__
#define __COURSEGEN_WIDGET_H__

#include <memory>

#include <Qt>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QString>

#include "core/map_view.h"

class QAction;
class QBoxLayout;
class QCheckBox;
class QEvent;
class QModelIndex;
class QTableView;
class QToolButton;
class QVariant;

namespace OpenOrienteering {

class Map;
class MapEditorController;
class Template;
class TemplateTableModel;

class CourseGenWidget : public QWidget
{
    Q_OBJECT

public:
    ~CourseGenWidget() override;

    CourseGenWidget(Map& map, MapView& main_view, MapEditorController& controller, QWidget* parent = nullptr);
    CourseGenWidget(const CourseGenWidget&) = delete;
    CourseGenWidget(CourseGenWidget&&) = delete;
    CourseGenWidget& operator=(const CourseGenWidget&) = delete;
    CourseGenWidget& operator=(CourseGenWidget&&) = delete;

signals:

protected:
    void generateCourse();

private:
    Map& map;
    MapView& main_view;
    MapEditorController& controller;
    bool mobile_mode;

    QPushButton* generate_button;
};

} // namespace OpenOrienteering

#endif // __COURSEGEN_WIDGET_H__