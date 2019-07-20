<?php
    // phpinfo();
    error_reporting(E_ALL);
    ini_set("display_errors", "1");
?>

<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="content-type" content="text/html" charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <title>MySQL Connect : View user records</title>

        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    </head>
    
    <body>

        <div class="bg-light">
            <div class="container">
                <!-- Start of navigation bar  -->
                <div class="navbar navbar-expand-lg navbar-light">
                        
                    <a href="" class="navbar-brand">My Records</a>

                    <button type="button" class="navbar-toggler" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                        <span class="navbar-toggler-icon"></span>
                    </button>

                    <div class="navbar-collapse collapse ">
                        <ul class="navbar-nav mr-auto">
                            <li class="nav-item active"><a href="view-record.php" class="nav-link">View Records</a></li>
                            <li class="nav-item"><a href="insert-record.php" class="nav-link">Insert Records</a></li>
                        </ul>
                    </div> <!-- Collapsed area for navbar while expanding -->

                </div> <!-- End of navbar -->
            </div>
        </div>

        <!-- Part to build connection to remote database -->
        <div class="container mt-3">
            
            <h1>Users Record</h1>

            <?php

                // Establish the linking to db, open it and return the link (or pointer)
                $mysql = mysqli_connect("local", "vincent", "+-*/1234", "table");

                // Case if there is error with the connection to database 
                if(!$mysql){
                    echo "Error : Unable to connect to MySQL <br>";
                    echo "Debugging Errno : " . mysqli_connect_errno() . "<br>";
                    echo "Debugging Error : " . mysqli_connect_error() . "<br>";
                    
                    exit();
                }

                // Else
                // echo "Success! Connection to MySQL remote database
                // echo "Connection Information : " . mysqli_get_host_info($mysql) ; 
                echo "<br>";

                // MySQL queries that sent to the server
                $str_query = "SELECT * FROM user";

                // Return the values of str_query given and executed by databadr
                $query = mysqli_query($mysql, $str_query);

                if(!$query)
                    echo "Errors : " . mysqli_error($mysql) . "<br>";
                else{
                    
                    echo "<table class=\" table table-striped table-bordered table-hover\">";

                    echo "<thead>";
                    
                    // Table header row
                    echo "<tr>";
                    echo "<th>First Name</th>";
                    echo "<th>Last Name</th>";
                    echo "<th>Email Address</th>";
                    echo "<th>Password</th>";
                    echo "<th>Actions</th>";
                    echo "</tr>";
                    echo "</thead>";
                    echo "<tbody>";

                    // Displaying data on each data entry (each row in the database table) from database
                    while($row = mysqli_fetch_array($query)){
                        
                        echo "<tr>";
                        echo "<td>" . $row["firstName"] . "</td>";
                        echo "<td>" . $row["lastName"] . "</td>";
                        echo "<td>" . $row["emailAddress"] . "</td>";
                        echo "<td>" . $row["password"] . "</td>";

                        // Buttons for edit and delete data entry with the reference of each row with their ID number in database
                        // Using location.href to redirect the current webpage to the file with given URL
                        echo "<td><button onclick=\"location.href='edit-record.php?idUser=" . $row["idUser"]."'\" class=\"btn btn-sm btn-light\">Edit</button>
                            &nbsp;&nbsp;<button onclick=\"location.href='delete-record.php?idUser=" . $row["idUser"] ."'\" class=\"btn btn-sm btn-danger\">Delete</button></td>";

                        echo "</tr>";
                    }

                    echo "</tbody>";
                    echo "</table>";

                    
                }

                mysqli_close($mysql);
            ?>

        </div>

        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    </body>
</html>