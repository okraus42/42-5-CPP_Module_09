/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:22:51 by okraus            #+#    #+#             */
/*   Updated: 2024/05/18 16:42:19 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLOURS_HPP
# define COLOURS_HPP
# include <iostream>
# include <stdint.h>

# define ERROR_COLOUR "\033[1;5;38:5:226;48:5:196m"
# define NO_COLOUR "\033[0m"

void		ft_colorize(uintptr_t i);
std::string	ft_str_colorize(uintptr_t i);
void		ft_uncolorize(void);

#endif
