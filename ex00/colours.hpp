/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:22:51 by okraus            #+#    #+#             */
/*   Updated: 2024/06/03 11:34:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLOURS_HPP
# define COLOURS_HPP
# include <iostream>
# include <stdint.h>

# define ERROR_COLOUR "\033[1;5;38:5:226;48:5:196m"
# define RED_COLOUR "\033[1;38:5:231;48:5:196m"
# define GREEN_COLOUR "\033[1;38:5:0;48:5:46m"
# define BLUE_COLOUR "\033[1;38:5:231;48:5:21m"
# define CYAN_COLOUR "\033[1;38:5:0;48:5:51m"
# define MAGENTA_COLOUR "\033[1;38:5:231;48:5:201m"
# define YELLOW_COLOUR "\033[1;38:5:0;48:5:226m"
# define WHITE_COLOUR "\033[1;38:5:0;48:5:231m"
# define BLACK_COLOUR "\033[1;38:5:231;48:5:0m"
# define NO_COLOUR "\033[0m"

void		ft_colorize(uintptr_t i);
std::string	ft_str_colorize(uintptr_t i);
void		ft_uncolorize(void);

#endif
