/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:55 by Manny             #+#    #+#             */
/*   Updated: 2023/05/01 13:54:53 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# include "libft.h"
//# include "/usr/local/opt/readline"

# define PROMPT "\001\e[0m\e[1;35m\002 MannyShell>$ \001\e[0m\002"
# define HEREDOC_NAME "/tmp/.minishell_heredoc_"

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

/* By defining PATH_MAX with a specific value, Minishell can use PATH_MAX
consistently across different systems,
regardless of how limits.h is implemented
*/
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# define SUCCESS 0
# define FAILURE 1

/* -------- GLOBAL VARIABLE ---------------- */
extern int	g_last_exit_code;

/* -------- STRUCTS ---------------- */
typedef struct s_token
{
	char			*str;
	char			*str_backup;
	bool			var_exists;
	int				type;
	int				status;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_copy;
	int		stdout_copy;
}	t_io_fds;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	char			*path;
	bool			pipe_output;
	int				pipe_fd;
	struct s_cmd	*prev;
	struct s_cmd	*next;
	t_io_fds		io_fds; 
}	t_cmd;

typedef struct s_data
{
	bool		interactive;
	char		*user_input;
	char		**envp;
	char		*wd;
	char		*old_wd;
	pid_t		pid;
	t_token		*token;
	t_cmd		*cmd;
}	t_data;

/* -------- INITIALIZE ---------------- */
bool	init_data(t_data *data char **envp);
bool	init_io(t_cmd *cmd);

#endif
