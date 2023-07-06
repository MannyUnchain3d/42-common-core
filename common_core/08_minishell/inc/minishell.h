/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:55 by Manny             #+#    #+#             */
/*   Updated: 2023/06/28 16:01:27 by etetopat         ###   ########.fr       */
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
# include <termios.h>
# include <dirent.h>

# include "libft.h"

/* Start and end of input */
# define DEMARK "\t \n\0"
# define QUOTES "'\""

# define PROMPT "\001\e[0m\e[1;35m\002 minishell>$ \001\e[0m\002"
# define HEREDOC_NAME ".minishell_heredoc_"

# define CMD_NOT_EXECUTABLE 126
# define CMD_NOT_FOUND 127

/* minishell can use PATH_MAX consistently across different systems,
 * regardless of how limits.h is implemented */
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

/* -------- GLOBAL VARIABLE ---------- */
extern char	**environ;

/* -------- STRUCTS ------------------ */
typedef struct s_io_fds
{
	char	**infile;
	char	**outfile;
	char	**append;
	char	**heredoc_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		fd_append;
	int		stdin_backup;
	int		stdout_backup;
}	t_io_fds;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	char			*path;
	bool			pipe_output;
	int				pipe_fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
	t_io_fds		*io_fds;
}	t_cmd;

typedef struct s_data
{
	bool				interactive;
	char				*user_input;
	char				**env;
	char				*wd;
	char				*old_wd;
	int					last_exit_code;
	pid_t				pid;
	t_cmd				*cmd;
	struct sigaction	sigint;
	struct sigaction	sigquit;
	struct termios		parent;
	struct termios		child;
	struct termios		original;
}	t_data;

/* ---- INITIALIZE -------------------- */
bool	init_data(t_data *data);
void	init_io(t_cmd *cmd);

/* ---- PARSER ------------------------ */
int		wordlen(char *str);
int		parse_user_input(t_data *data);
char	*handling_input(char *input);
t_list	*input_split(char *line);
int		add_token(t_list **token, char *line);
void	free_token(void *content);
void	parsing(t_list **tokens, t_data *data);
int		parse_other(char *token, t_data *data, char **new);
int		parse_dquote(char *token, t_data *data, char **new);
int		is_redirect(char *str);
int		is_opt(char *str);
int		precheck_token(t_list **tokens);
int		check_token(t_list **tokens);
int		exp_other(char *token, char **new);
int		exp_s_quote(char *token, char **new);
int		exp_d_quote(char *token, char **new);
int		exp_env(char *token, t_data *data, char **new);

/* ---- CMD GROUP --------------------- */
t_cmd	*group_cmd(t_list *tokens);
char	**cmd_table(t_list *tokens, const char *sig, int count);
char	*erase_q(char *content);
int		check_redirect(t_cmd *tmp);
void	clear_cmd(t_cmd *cmd);
void	set_signals_interactive(t_data *data);
void	set_signals_child(t_data *data);
void	set_signals_noninteractive(t_data *data);
void	handle_sig(int signo);
void	init_termios(t_data *data);

/* ---- EXECUTION --------------------- */
//BUILTINS:
int		cd_builtin(t_data *data, char **args);
int		echo_builtin(t_data *data, char **args);
int		env_builtin(t_data *data, char **args);
int		exit_builtin(t_data *data, char **args);
int		export_builtin(t_data *data, char **args);
int		pwd_builtin(t_data *data, char **args);
int		unset_builtin(t_data *data, char **args);

// ENV.C:
int		env_var_count(char **env);
int		get_env_var_index(char **env, char *var);
char	*get_env_var_value(char **env, char *var);
bool	is_valid_env_var_key(char *var);

// SET_ENV.C:
bool	set_env_var(t_data *data, char *key, char *value);
bool	remove_env_var(t_data *data, int index);

// EXECUTE.C:
int		execute(t_data *data);
int		execute_cmd(t_data *data, t_cmd *cmd);
int		parent_built_check(t_data *data);
int		execute_builtin(t_data *data, t_cmd *cmd);
int		execute_builtin_parent(t_data *data, t_cmd *cmd, int ret);
int		create_children_2(t_data *data);
int		execute_local_bin(t_data *data, t_cmd *cmd);
int		execute_sys_bin(t_data *data, t_cmd *cmd);
int		get_children(t_data *data);

// EXECUTE_UTILS.C:
int		check_cmd_not_found(t_data *data, t_cmd *cmd);
bool	cmd_is_dir(char *cmd);
void	exit_shell(t_data *data, int exno);
void	free_data(t_data *data, bool clear_history, bool clear_input);
void	close_fds(t_cmd *cmds, bool close_backups);
void	free_io(t_io_fds *io);
void	free_str_tab(char **tab);
void	free_ptr(void *ptr);
void	execute_cmd_chain(t_data *data, t_cmd *cmd, int ret);

// FILE_IO.C:
bool	check_infile_outfile(t_io_fds *io);
bool	redirect_io(t_io_fds *io);
bool	restore_io(t_io_fds *io);
int		place_fd(t_cmd *cmd);
bool	set_redir_fds(t_cmd *cmd);
int		heredoc_imp(t_cmd *cmd, t_data *data);
void	heredoc_free(t_data *data);
void	here_env(char **buffer, t_data *data);
int		here_error(char *name, char *delimit, int option);

// PARSE_PATH.C:
char	*get_cmd_path(t_data *data, char *cmd);

// PIPE.C:
bool	create_pipes(t_data *data);
bool	set_pipe_fds(t_cmd *cmds, t_cmd *curr_cmd);
void	close_pipe_fds(t_cmd *cmds, t_cmd *skip_cmd);

/* ---- ERROR & EXIT HANDLING --------- */
// ERROR.C:
void	errmsg(char *errmsg, char *detail, int quotes);
int		errmsg_cmd(char *cmd, char *detail, char *error_msg, int error_nb);
bool	usage_msg(bool return_value);

// SIGNAL_EXIT_STATUS.C:
int		handle_exit_status(int save_stat);

#endif
