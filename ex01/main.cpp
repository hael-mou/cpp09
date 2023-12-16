/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:57:44 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/28 11:46:22 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		if (argc != 2) {
			throw (std::invalid_argument("Error : expected one argument !!"));
		}
		std::cout << RPN::calculate(argv[1]) << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
