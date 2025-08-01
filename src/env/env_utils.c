/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 04:25:13 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/01 04:55:59 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_value(char *var, t_data *data)
{
	size_t	v_len;
	t_env	*tmp;

	if (!var || !data || !data->env)
		return (NULL);
	v_len = ft_strlen(var);
	tmp = data->env;
	while (tmp)
	{
		if (ft_strlen(tmp->key) == v_len && !ft_strncmp(tmp->key, var, v_len))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	list_len(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 1;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	env_count(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**env_to_array(t_data *data)
{
	char	**array;
	int		i;

	if (!data->env || !data->envp)
		return (NULL);
	array = ft_malloc(sizeof(char *) * (env_count(data->env) + 1), 69);
	i = 0;
	while (i < env_count(data->env))
	{
		array[i] = ft_strdup(data->envp[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
