<?php
    // phpinfo();
    error_reporting(E_ALL);
    ini_set("display_errors", "1");

    $idUser = $_GET["idUser"];
    $idUser = filter_var($idUser, FILTER_SANITIZE_MAGIC_QUOTES);
    $idUser = filter_var($idUser, FILTER_SANITIZE_STRING);

?>

<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="content-type" content="text/html" charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <title>MySQL Connect : Edit user record</title>

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
        <div class="container">
            
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

                // MySQL queries that sent to the server : Deletion of selected entry
                $str_query = "DELETE FROM user WHERE idUser=$idUser";

                // Return the values of str_query given and executed by database
                $query = mysqli_query($mysql, $str_query);

                if(!$query){
            ?>

            <div class="alert alert-danger">
                <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
                <strong>Error !</strong> Unable to delete selected data entry from data base :<br><?php echo mysqli_error($mysql)?><br>
            </div>

            <?php
                }
                else{
            ?>

            <div class="alert alert-success">
                <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
                <strong>Success !</strong> The recorded has been deleted !<br>
                <a href="view-record.php">Click here</a> to view all the remaining records
            </div>

            <?php    
                }

                mysqli_close($mysql);
            ?>

        </div>

        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    </body>
</html>