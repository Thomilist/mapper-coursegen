#include "coursegen_widget.h"

#include <utility>
#include <vector>

#include <Qt>
#include <QtGlobal>
#include <QAction>
#include <QCoreApplication>
#include <QEvent>
#include <QPushButton>
#include <QStyle>
#include <QStyleOption>
#include <QStyleOptionButton>

#ifdef __clang_analyzer__
#define singleShot(A, B, C) singleShot(A, B, #C) // NOLINT 
#endif

#include "settings.h"
#include "core/georeferencing.h"
#include "core/map.h"
#include "fileformats/file_format_registry.h"
#include "fileformats/file_import_export.h"
#include "gui/file_dialog.h"
#include "gui/main_window.h"
#include "gui/util_gui.h"
#include "gui/map/map_editor.h"
#include "gui/map/map_widget.h"
#include "gui/widgets/segmented_button_layout.h"
#include "tools/tool.h"
#include "util/item_delegates.h"

namespace OpenOrienteering {

CourseGenWidget::~CourseGenWidget() = default;

CourseGenWidget::CourseGenWidget(Map& map, MapView& main_view, MapEditorController& controller, QWidget* parent)
: QWidget(parent)
, map(map)
, main_view(main_view)
, controller(controller)
, mobile_mode(controller.isInMobileMode())
{
    QStyleOption style_option(QStyleOption::Version, QStyleOption::SO_DockWidget);

    auto* generate_widget = new QWidget();
    auto* generate_layout = new QVBoxLayout(generate_widget);

    generate_button = new QPushButton(tr("Generate"), this);
    generate_layout->addWidget(generate_button);

    generate_layout->setContentsMargins(
	            style()->pixelMetric(QStyle::PM_LayoutLeftMargin, &style_option) / 2,
	            style()->pixelMetric(QStyle::PM_LayoutTopMargin, &style_option) / 2,
	            style()->pixelMetric(QStyle::PM_LayoutRightMargin, &style_option) / 2,
	            0 // Covered by the main layout's spacing.
    );

    setLayout(generate_layout);
    generate_button->setEnabled(true);

    connect(generate_button, &QAbstractButton::clicked, this, &CourseGenWidget::generateCourse);
}

void CourseGenWidget::generateCourse()
{
    
}

} // namespace OpenOrienteering