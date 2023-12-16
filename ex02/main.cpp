/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:38:04 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/16 10:19:52 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Pmerge.hpp"
# include "Vector.hpp"
#include "LinkedList.hpp"
# include <iostream>
# include <ctime>

int		main(int argc, char const *argv[])
{
	try
	{
		Pmerge pmerge(new Vector());
		pmerge.initContainer(++argv);
		clock_t start_time = clock();
		std::cout << "* Before: "; pmerge.display();
		pmerge.mergeInsertionSort();
		clock_t end_time = clock();
		std::cout << "* After: "; pmerge.display();
		double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << "~ Time to process with ~ std::vector ~ is : ";
		std::cout <<  elapsed_time <<" us\n" << std::endl;

		Pmerge pmerge2(new LinkedList());
		pmerge2.initContainer(argv);
		std::cout << "* Before: "; pmerge2.display();
		start_time = clock();
		pmerge2.mergeInsertionSort();
		end_time = clock();
		std::cout << "* After: "; pmerge2.display();
		elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << "~ Time to process with ~ std::list ~ is : ";
		std::cout <<  elapsed_time <<" us\n" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " <<e.what() << '\n';
	}
}
