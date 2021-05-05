//
//


#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "doctest.h"
using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace doctest;

TEST_CASE ("Medic") {
    Board board;

    CHECK(board.is_clean());
// put disease cube in Cities
    board[City::Kinshasa] = 3;      
    board[City::Kinshasa] = 2;      
    board[City::MexicoCity] = 3;    
    board[City::HoChiMinhCity] = 1; 
    board[City::Chicago] = 10;

    Medic player {board, City::Chicago};  
    player.take_card(City::Johannesburg)
            .take_card(City::MexicoCity)
            .take_card(City::SaoPaulo)
            .take_card(City::BuenosAires)
            .take_card(City::HoChiMinhCity);
            CHECK(player.role()==string("Medic"));
            player.take_card(City::Chicago);
    player.build();
    player.treat(City::Chicago);
    CHECK(board[City::Chicago] == 0);
    Researcher researcher {board, City::MexicoCity};
   researcher.take_card(City::Lagos)
            .take_card(City::Kinshasa)
            .take_card(City::LosAngeles)
            .take_card(City::Lima)
            .take_card(City::Miami);
    researcher.discover_cure(pandemic::Color::Yellow);
    player.drive(City::MexicoCity);
    CHECK(board[City::MexicoCity] == 0);
    CHECK_THROWS_AS(player.fly_shuttle(City::Mumbai), std::invalid_argument);
    CHECK_THROWS_AS(player.fly_direct(City::Shanghai), std::invalid_argument);
    CHECK_THROWS_AS(player.drive(City::Manila), std::invalid_argument);
    CHECK_THROWS_AS(player.treat(City::MexicoCity), std::invalid_argument);
}

TEST_CASE ("researcher") {
    Board board;

    CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Cairo] = 2;
    board[City::Kolkata] = 2;
    board[City::HongKong] = 3;
    board[City::London] = 3;


    Researcher player {board, City::London};  
    player.take_card(City::HongKong)
            .take_card(City::MexicoCity)
            .take_card(City::Cairo)
            .take_card(City::Atlanta)
            .take_card(City::HoChiMinhCity);
            CHECK(player.role()==string("Researcher"));
player.take_card(City::London);
    player.build();
    player.treat(City::London);
            CHECK(board[City::London] == 2);
    player.fly_direct(City::HongKong);

    player.take_card(City::Sydney)
            .take_card(City::Osaka)
            .take_card(City::Beijing)
            .take_card(City::Tokyo)
            .take_card(City::Manila);
    player.discover_cure(pandemic::Color::Red);
    Medic medic {board, City::HongKong};
            CHECK(board[City::HongKong] == 0);
            CHECK_THROWS_AS(player.fly_shuttle(City::London), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_direct(City::BuenosAires), std::invalid_argument);
            CHECK_THROWS_AS(player.drive(City::Tehran), std::invalid_argument);
            CHECK_THROWS_AS(player.treat(City::HongKong), std::invalid_argument);
}


TEST_CASE ("Virologist") {
    Board board;

    CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Delhi] = 9;
    board[City::Lagos] = 2;
    board[City::Taipei] = 3;
    board[City::Kolkata] = 3;

    Virologist player {board, City::Miami};  
    player.take_card(City::Delhi)
            .take_card(City::Kolkata)
            .take_card(City::Lima)
            .take_card(City::Madrid);
    player.fly_direct(City::Delhi);
    player.take_card(City::Delhi);
    player.build();
    CHECK(player.role()==string("Virologist"));
    player.take_card(City::Delhi);

    player.treat(City::Delhi);
    player.take_card(City::Taipei);

    player.treat(City::Taipei);
    player.treat(City::Kolkata);


    CHECK(board[City::Delhi]==8);
    CHECK(board[City::Taipei]==2);
    CHECK(board[City::Kolkata]==2);


    player.drive(City::Kolkata);
    player.take_card(City::Kolkata);
    player.build();
    CHECK_THROWS(player.discover_cure(pandemic::Color::Black));
    player.take_card(City::Paris);
            CHECK_THROWS_AS(player.fly_shuttle(City::Paris), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_direct(City::BuenosAires), std::invalid_argument);
            CHECK_THROWS_AS(player.drive(City::Cairo), std::invalid_argument);
            CHECK_THROWS_AS(player.treat(City::Bogota), std::invalid_argument);
}


TEST_CASE ("OperationsExpert") {
    Board board;

            CHECK(board.is_clean());
    // put disease cube in Cities

    board[City::Manila] = 5;

    board[City::Kinshasa] = 2;      
    board[City::Osaka] = 7;    
    board[City::Moscow] = 8; 

    OperationsExpert player {board, City::Madrid};  
    player.take_card(City::Manila)
            .take_card(City::Osaka)
            .take_card(City::Moscow)
            ;
player.fly_direct(City::Moscow);
player.take_card(City::Moscow);
player.build();

player.treat(City::Moscow);
    player.treat(City::Moscow);
    player.treat(City::Moscow);
    player.treat(City::Moscow);
    player.treat(City::Moscow);
    player.treat(City::Moscow);
    player.treat(City::Moscow);
player.treat(City::Moscow);
            CHECK(player.role()==string("OperationsExpert"));

            CHECK(board[City::Moscow] == 0);
            CHECK_THROWS_AS(player.treat(City::Moscow), std::invalid_argument);
            CHECK_THROWS_AS(player.drive(City::Manila), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_direct(City::Chicago), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_shuttle(City::Osaka), std::invalid_argument);
            CHECK_THROWS_AS(player.discover_cure(pandemic::Color::Black), std::invalid_argument);
}



TEST_CASE ("Dispatcher") {
    Board board;

            CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Miami] = 8;

    board[City::Montreal] = 8;      
    board[City::Riyadh] = 8;    

    Dispatcher player{board, City::Bogota};  
    player.take_card(City::Miami)
            .take_card(City::Montreal)
            .take_card(City::Bogota)
            .take_card(City::Washington)

            .take_card(City::Riyadh);
    player.build();
    player.fly_direct(City::Washington);
            CHECK(player.role() == string("Dispatcher"));

            CHECK(board[City::Washington] == 0);
            CHECK_THROWS_AS(player.treat(City::Washington), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_shuttle(City::Miami), std::invalid_argument);


}


TEST_CASE ("Scientist") {
    Board board;

            CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Kolkata] = 7;

    board[City::Karachi] = 8;      
    board[City::Tehran] = 8;    
    board[City::Istanbul] = 8;    
    board[City::HongKong] = 8;    

    Scientist player{board, City::Sydney, 3};  
    player.take_card(City::Kolkata)
            .take_card(City::Karachi)
            .take_card(City::Istanbul)
            .take_card(City::HongKong)
            .take_card(City::Tehran);
    player.fly_direct(City::HongKong);
    player.drive(City::Kolkata);
    player.build();
    player.discover_cure(pandemic::Color::Black);
    player.take_card(City::Kolkata);
    player.treat(City::Kolkata);
            CHECK(board[City::Kolkata] == 0);
            CHECK_THROWS_AS(player.treat(City::Kolkata), std::invalid_argument);
    CHECK(player.role() == string("Scientist"));
            CHECK_THROWS_AS(player.fly_direct(City::Milan), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_shuttle(City::Tokyo), std::invalid_argument);


}



TEST_CASE ("GeneSplicer") {
    Board board;

            CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Bangkok] = 8;
    board[City::Taipei] = 8;      
    board[City::Osaka] =3;    
    board[City::Shanghai] =3;    
    board[City::HoChiMinhCity] =3;    
    board[City::StPetersburg] =3;    

    GeneSplicer player{board, City::StPetersburg};  
    player.take_card(City::Bangkok)
            .take_card(City::Taipei)
            .take_card(City::Shanghai)
            .take_card(City::HoChiMinhCity)
            .take_card(City::StPetersburg)

            .take_card(City::Osaka);
    player.build();
            player.discover_cure(pandemic::Color::Blue);
       player.treat(City::StPetersburg);
            CHECK(board[City::StPetersburg] == 0);
            CHECK_THROWS_AS(player.treat(City::StPetersburg), std::invalid_argument);
            CHECK(player.role() == string("GeneSplicer"));
            CHECK_THROWS_AS(player.fly_direct(City::Mumbai), std::invalid_argument);
            CHECK_THROWS_AS(player.treat(City::Istanbul), std::invalid_argument);
            CHECK_THROWS_AS(player.drive(City::Atlanta), std::invalid_argument);
            CHECK_THROWS_AS(player.fly_shuttle(City::Lima), std::invalid_argument);


}




TEST_CASE ("FieldDoctor") {
    Board board;

            CHECK(board.is_clean());
// put disease cube in Cities

    board[City::Madrid] = 4;
    board[City::Paris] = 3;
    board[City::Lagos] = 2;
    board[City::Tokyo] = 1;

    FieldDoctor player{board, City::NewYork};
    player.take_card(City::Tokyo)
            .take_card(City::Lagos)
            .take_card(City::Paris)
            .take_card(City::Madrid)

            .take_card(City::Osaka);

    player.treat(City::Madrid);
            CHECK(board[City::Madrid] == 3);
    player.treat(City::Madrid);
            CHECK(board[City::Madrid] == 2);
    player.drive(City::Madrid);
    player.treat(City::Paris);
            CHECK(board[City::Paris] == 2);

    Researcher researcher{board, City::Paris};
    researcher.take_card(City::Washington)
            .take_card(City::Milan)
            .take_card(City::Atlanta)
            .take_card(City::Chicago)

            .take_card(City::Essen);
    researcher.discover_cure(pandemic::Color::Blue);
    researcher.take_card(City::Paris);
    researcher.treat(City::Paris);
            CHECK(board[City::Paris] == 0);

    CHECK_THROWS_AS(player.treat(City::Paris), std::invalid_argument);
            CHECK(player.role() == string("FieldDoctor"));
    CHECK_THROWS_AS(player.fly_direct(City::Shanghai), std::invalid_argument);
    CHECK_THROWS_AS(player.drive(City::Kinshasa), std::invalid_argument);
    CHECK_THROWS_AS(player.fly_shuttle(City::Lagos), std::invalid_argument);


}












