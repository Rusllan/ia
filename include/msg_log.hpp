#ifndef MSG_LOG_HPP
#define MSG_LOG_HPP

#include <string>
#include <vector>

#include "colors.hpp"
#include "rl_utils.hpp"
#include "global.hpp"
#include "info_screen_state.hpp"

class Msg
{
public:
        Msg(const std::string& text,
            const Color& color_id,
            const int x_pos) :
                color_(color_id),
                x_pos_(x_pos),
                str_(text),
                repeats_str_(""),
                nr_(1) {}

        Msg() :
                color_(colors::white()),
                x_pos_(0),
                str_(""),
                repeats_str_(""),
                nr_(1) {}

        void str_with_repeats(std::string& str_ref) const
        {
                str_ref = str_ + (nr_ > 1 ? repeats_str_ : "");
        }

        void str_raw(std::string& str_ref) const
        {
                str_ref = str_;
        }

        void incr_repeat()
        {
                ++nr_;

                repeats_str_ = "(x" + std::to_string(nr_) + ")";
        }

        Color color_;
        int x_pos_;

private:
        std::string str_;
        std::string repeats_str_;
        int nr_;
};

namespace msg_log
{

void init();

void draw();

void add(const std::string& str,
         const Color& color_id = colors::text(),
         const bool interrupt_all_player_actions = false,
         const MorePromptOnMsg add_more_prompt_on_msg = MorePromptOnMsg::no);

// NOTE: This function can safely be called at any time. If there is content in
// the log, a "more" prompt will be done, and the log is cleared. If the log
// happens to be empty, nothing is done.
void more_prompt();

void clear();

void add_line_to_history(const std::string& line_to_add);

const std::vector< std::vector<Msg> > history();

} // log

// -----------------------------------------------------------------------------
// Message history state
// -----------------------------------------------------------------------------
class MsgHistoryState: public InfoScreenState
{
public:
        MsgHistoryState() :
                InfoScreenState(),
                top_line_nr_(0),
                btm_line_nr_(0),
                history_() {}

        ~MsgHistoryState() {}

        void on_start() override;

        void draw() override;

        void update() override;

        StateId id() override;

private:
        std::string title() const override;

        InfoScreenType type() const override
        {
                return InfoScreenType::scrolling;
        }

        int top_line_nr_;
        int btm_line_nr_;

        std::vector< std::vector<Msg> > history_;
};

#endif // MSG_LOG_HPP
