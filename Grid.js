import { render } from '@testing-library/react';
import React, { Component } from 'react';
import Cell from './cell/Cell.js'
import './grid.css';

class Grid extends Component{
    constructor(props){
        super(props)
        this.grid = []
        this.state = {
            test: <Cell  xpos={99} ypos={99} life={1}></Cell>
        }
    }

    populateGrid(){
        var x = 0;
        var y = 0;
        for(x=0; x<15; x++){
            // items = []
            for(y=0; y<15; y++){
                var cell = <Cell 
                    key={1}
                    xpos={x} 
                    ypos={y} 
                    life={0}>
                    </Cell>
               
                this.grid.push(cell);
            }
            // this.props.grid.push(items)
        }
    }

    findNeighbours(cell){
        var neihgbours = []

    }

    itterateGrid(){
        console.log(this.state);
        // this.state.test.props.life = 1;
        console.log(this.state.test.props.life);
        
        // var grid = this.grid
        // for(var i in grid){
            // let string = grid[i].props.xpos.toString() + grid[i].props.xpos.toString()
            // if (this.grid[i].xpos === 3){
                
                // console.log(grid[i].state);
                // grid[i].handleClick;
            // }
            // console.log(grid[i]);
        //     // this.findNeighbours(grid[i])
        // }
    }
    render(){
        this.populateGrid()
        this.itterateGrid()
        return (
            <div className="grid">
                {this.grid.map((i) => {
                // console.log(i);
                
                return <div key={i.xpos,i.ypos}>{i}</div>;
              
                })}      
                          
            </div>
        )
    }
}
export default Grid;