#ifndef PANEL_HPP
#define PANEL_HPP

struct PxPos;
class R;
class P;

enum class Panel
{
        screen,
        map,
        player_stats,
        equipped,
        log,
        properties,
        create_char_menu,
        create_char_descr,
        item_menu,
        item_descr,
        END
};

namespace panels
{

void init(const P max_gui_dims);

bool is_valid();

R get_area(const Panel panel);

P get_dims(const Panel panel);

P get_p0(const Panel panel);

P get_p1(const Panel panel);

int get_x0(const Panel panel);

int get_y0(const Panel panel);

int get_x1(const Panel panel);

int get_y1(const Panel panel);

int get_w(const Panel panel);

int get_h(const Panel panel);

int get_center_x(const Panel panel);

int get_center_y(const Panel panel);

} // panels

#endif // PANEL_HPP
