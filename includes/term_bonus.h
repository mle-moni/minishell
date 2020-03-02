
#ifndef _TERM_BONUS_H
# define _TERM_BONUS_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include "keys.h"

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_editor
{
	char				*term_type;
	t_coord				pos;
	t_coord				init_pos;
	char				*buf;
	struct termios		orig_termios;
	t_list				**histo;
	t_list				*histo_pos;
	char				*buf_save;
}						t_editor;

/*
** term.c
*/

void					editor_error(const char *str);
t_editor				init_editor(t_list **env_list);

/*
** termios_reader.c
*/

int						termios_read_line(char **line, t_editor *editor);

/*
** cursor.c
*/

t_coord					get_cur_pos(void);
void					set_cur_pos(int x, int y, t_editor *editor);

/*
** term_utils.c
*/

int						ctrl_key(char c);

/*
** histo.c
*/

char					*put_next_histo_in_buf(t_editor *editor);
char					*put_prev_histo_in_buf(t_editor *editor);

#endif
